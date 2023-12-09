#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include <fstream>
#include <sstream>
#include "../Modules/parser.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class http_server {
public:
    http_server() : m_listener(U("http://localhost:13931")) {
        m_listener.support(methods::GET, std::bind(&http_server::handle_get, this, std::placeholders::_1));
        m_listener.support(methods::POST, std::bind(&http_server::handle_post, this, std::placeholders::_1));
    }

    void handle_get(http_request request) {
        if (request.relative_uri().path() != U("/")) {
            request.reply(status_codes::NotFound, "Page not found");
            return;
        }

        // Read HTML page from file
        // If it isn't found, return error
        std::ifstream file("./html/index.html");
        if (!file.is_open()) {
            request.reply(status_codes::NotFound, "HTML file not found");
            return;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        http_response response(status_codes::OK);
        response.set_body(buffer.str());
        response.headers().add(U("Content-Type"), U("text/html"));
        request.reply(response);
    }

    void handle_post(http_request request) {
        request.extract_json().then([this, request](json::value requestBody) {
            if (requestBody.is_null()) {
                request.reply(status_codes::BadRequest);
                return;
            }

            auto expression = requestBody[U("expression")].as_string();
            auto argument = requestBody[U("argument")].as_string();
            auto factorize = requestBody[U("factorize")].as_bool();
            auto reduceRoots = requestBody[U("reduceRoots")].as_bool();

            json::value responseBody;
            try {
                Parser p;
                auto resp = p.parse(expression);
                responseBody[U("result")] = json::value::string(resp);
            } catch (std::exception &e) {
                responseBody[U("result")] = json::value::string(e.what());
            }

            http_response response(status_codes::OK);
            response.set_body(responseBody);

            request.reply(response);
        });
    }

    void start() {
        m_listener.open().wait();
    }

private:
    http_listener m_listener;
};
