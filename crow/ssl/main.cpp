#define CROW_ENABLE_SSL
#include "crow_all.h"


crow::ssl_context_t get_ssl_context(){
    
    auto context = crow::ssl_context_t(crow::ssl_context_t::sslv23);
    context.set_verify_mode(boost::asio::ssl::verify_peer);
    context.set_verify_mode(boost::asio::ssl::verify_client_once);
    context.set_password_callback(std::bind([]{
        return "ysh8361";
    }));
    context.use_certificate_file("/etc/ssl/certs/cert.pem", crow::ssl_context_t::pem);
    context.use_private_key_file("/etc/ssl/certs/key.pem", crow::ssl_context_t::pem);
    context.set_options(
            boost::asio::ssl::context::default_workarounds
                  | boost::asio::ssl::context::no_sslv2
                  | boost::asio::ssl::context::no_sslv3
            );

    return context;
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello world!";
    });

    auto ctx = get_ssl_context();
    
    app.port(18080)
        .ssl(std::move(ctx))
        .multithreaded()
        .run();

}