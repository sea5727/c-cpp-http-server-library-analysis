#include <iostream>
#include "crow_all.h"


struct ExampleMiddleware{
    std::string message;

    ExampleMiddleware() {
        message = "foo";
    }

    void setMessage(std::string newMsg) {
        message = newMsg;
    }

    struct context{};

    void before_handle(crow::request& /*req*/, crow::response& /*res*/, context& /*ctx*/)
    {
        CROW_LOG_DEBUG << "[before_handle] - MESSAGE: " << message;
    }

    void after_handle(crow::request& /*req*/, crow::response& /*res*/, context& /*ctx*/)
    {
        CROW_LOG_DEBUG << "[after_handle] - MESSAGE: " << message;
    }
};

int main(int argc, char * argv[]){

    // crow::App<ExampleMiddleware> app;

    // app.get_middleware<ExampleMiddleware>().setMessage("hello");

    // CROW_ROUTE(app, "/")
    //     .name("hello")
    // ([]{
    //     return "hello world";
    // });
    crow::SimpleApp app;
    CROW_ROUTE(app, "/about")
    ([](){
        return "About Crow example.";
    });


    // enables all log
    app.loglevel(crow::LogLevel::CRITICAL);
    //crow::logger::setHandler(std::make_shared<ExampleLogHandler>());

    app.port(18080)
        .multithreaded()
        .run();

    return 0;
}