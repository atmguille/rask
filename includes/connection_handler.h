#ifndef CONNECTION_HANDLER_H
#define CONNECTION_HANDLER_H

#define MAX_BUFFER 8192
#define MAX_HEADERS 32
#define BASE_PATH "../www"
#define DEFAULT_PATH "/index.html"

#define OK 0
#define ERROR -1
#define CLOSE_CONNECTION -2
#define PARSE_ERROR -3

typedef struct _Request Request;

/**
 * Handles a connection with the client, reading a request and answering with the requested data
 * This function won't close client_fd.
 * @param client_fd
 * @return 0 if no errors occurred and -1 otherwise
 */
int connection_handler(int client_fd);

#endif // CONNECTION_HANDLER_H
