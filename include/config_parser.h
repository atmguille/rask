#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

/**
 * Struct containing server configuration attributes
 */
struct config {
    char *signature;
    char *base_path;
    char *default_path;
    int max_connections;
    int listen_port;
    int log_priority;
    int script_timeout;
    int socket_timeout;
};

/**
 * Fills the struct with the fields found in config_file
 * @param config_file_name
 */
struct config *config_load(char *config_file_name);

/**
 * Frees struct as well as the strings inside
 * @param sever_attrs
 */
void config_destroy(struct config *sever_attrs);

#endif //CONFIG_PARSER_H
