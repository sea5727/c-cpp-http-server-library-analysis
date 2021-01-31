#pragma once

#include "inc.hpp"

class listener : public std::enable_shared_from_this<listener> {
public:
    boost::asio::io_context & ios;
    boost::asio::ip::tcp::acceptor acceptor;
    std::shared_ptr<std::string const> doc_root;

public:
    listener(
        boost::asio::io_context & ios,
        boost::asio::ip::tcp::endpoint endpoint,
        std::shared_ptr<std::string const> const & doc_root) 
        : ios(ios)
        , acceptor(ios)
        , doc_root(doc_root) {

            boost::beast::error_code ec;

            acceptor.open(endpoint.protocol(), ec);
            if(ec) {
                return;
            }

            acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
            if(ec) {
                return;
            }

        }
        

    
};