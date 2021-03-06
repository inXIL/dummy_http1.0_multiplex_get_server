#include "tcp_addr.hh"
#pragma once

struct opt {
    struct Params {
        const TCPAddr addr;
        const std::string directory;
    };

    static Params parse_cli_params(int argc, char* argv[]) {
        std::string ip;
        std::string port;
        std::string directory;
        while(true) {
            const int opt = getopt(argc, argv, "h:p:d:");
            if (-1 == opt) break;
            switch(opt) {
                case 'h':
                    ip = optarg;
                    break;
                case 'p':
                    port = optarg;
                    break;
                case 'd':
                    directory = optarg;
                    break;
            }
        }
        if ("" == ip) {
            fprintf(stderr, "ip is mandatory");
            exit(EXIT_FAILURE);
        }
        if ("" == port) {
            fprintf(stderr, "port is mandatory");
            exit(EXIT_FAILURE);
        }
        if ("" == directory) {
            fprintf(stderr, "directory is mandatory");
            exit(EXIT_FAILURE);
        }
        const auto addr = TCPAddr::from_strs(ip, port);
        return Params {
            addr,
            directory,
        };
    }
};
