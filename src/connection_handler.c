#include "../includes/connection_handler.h"
#include "../srclib/logging/logging.h"
#include "../srclib/socket/socket.h"
#include "../includes/response.h"

enum http_method {
    GET,
    POST,
    OPTIONS,
    UNKNOWN
};


enum http_method _get_method(struct request *request) {
    if (string_is_equal_to(request->method, "GET")) {
        return GET;
    } else if (string_is_equal_to(request->method, "POST")) {
        return POST;
    } else if (string_is_equal_to(request->method, "OPTIONS")) {
        return OPTIONS;
    } else {
        print_warning("method not implemented");
        return UNKNOWN;
    }
}

int connection_handler(int client_fd, struct config *server_attrs) {
    struct request request;
    enum http_method method;
    int response_code;

    // Set client_fd socket timeout
    socket_set_timeout(client_fd, 10);

    response_code = process_request(client_fd, &request);
    if (response_code < 0) {
        if (response_code == BAD_REQUEST) {
            response_bad_request(client_fd, server_attrs);
        } else if (response_code == REQUEST_TOO_LONG) {
            response_request_too_long(client_fd, server_attrs);
        }
        return response_code;
    }

    method = _get_method(&request);
    if (method == UNKNOWN) {
        response_not_implemented(client_fd, server_attrs);
        return ERROR;
    } else if (method == GET) {
        response_get(client_fd, server_attrs, &request);
    } else if (method == POST) {
        response_post(client_fd, server_attrs, &request);
    } else if (method == OPTIONS) {
        response_options(client_fd, server_attrs);
    }


    return OK;
}