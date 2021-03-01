#define CROW_ENABLE_SSL
#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello world!";
    });

    app.loglevel(crow::LogLevel::CRITICAL);

    app.port(18080).ssl_file("./mycommoncrt.crt", "./private.key").run();
}