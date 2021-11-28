4
typedef uint64 void_p;

typedef uint8 u_char;

typedef uint32 uint32_t;

typedef int64 intptr_t;
typedef uint64 uintptr_t;
typedef uint64 time_t;

typedef int64 ssize_t;
typedef int64 off_t;
typedef uint64 size_t;

typedef uint16 in_port_t;

typedef intptr_t        ngx_int_t;
typedef uintptr_t       ngx_uint_t;
typedef intptr_t        ngx_flag_t;

typedef uint32 ngx_fd_t;
typedef uint64 ngx_atomic_t;
typedef uint64 ngx_buf_tag_t;

typedef struct {
    size_t      len;
    void_p data ; // u_char     *
} ngx_str_t;


typedef ngx_uint_t  ngx_rbtree_key_t;
typedef ngx_int_t   ngx_rbtree_key_int_t;
typedef ngx_rbtree_key_t      ngx_msec_t;
typedef ngx_rbtree_key_int_t  ngx_msec_int_t;

typedef struct {
    ngx_int_t    num;
    size_t       size;
} ngx_bufs_t;

typedef struct sockaddr_in {
    uint16 sin_family;
    uint16 sin_port;
    uint32 sin_addr;
    uint64 sin_zero;
} sockaddr_in_t;

typedef struct {
    void_p buckets;//ngx_hash_elt_t**
    ngx_uint_t        size;
} ngx_hash_t;

typedef struct {
    void_p elts;
    ngx_uint_t   nelts;
    size_t       size;
    ngx_uint_t   nalloc;
    void_p pool; //ngx_pool_t*
} ngx_array_t;



struct ngx_list_part_s {
    void_p elts; //void             *
    ngx_uint_t        nelts;
    void_p next; //ngx_list_part_t  *
} ngx_list_part_t;


typedef struct {
    void_p last; //ngx_list_part_t  *
    ngx_list_part_t   part;
    size_t            size;
    ngx_uint_t        nalloc;
    void_p pool; //ngx_pool_t       *
} ngx_list_t;

typedef struct {
    ngx_str_t                   value;
    void_p flushes ; // ngx_uint_t                 *
    void_p lengths;
    void_p values;

    union {
        size_t                  size;
    } u;
} ngx_http_complex_value_t;

typedef struct ngx_open_file_s {
    uint64              fd;
    ngx_str_t             name;

    void_p flush; // func ptr
    void_p data;
} ngx_open_file_t;

typedef struct ngx_log_s {
    ngx_uint_t log_level;
    void_p file ;//ngx_open_file_t *

    uint64 connection;

    time_t disk_full_time;

    void_p handler;//ngx_log_handler_pt
    void_p data ;//void *

    void_p writer;//ngx_log_writer_pt
    void_p wdata ;//void *

    void_p action ;//char *

    void_p next ;//ngx_log_t *
} ngx_log_t;

typedef struct {
    ngx_str_t name;
    size_t len;
    size_t level[3];

    void_p manager; //ngx_path_manager_pt
    void_p purger; //ngx_path_purger_pt
    void_p loader; //ngx_path_loader_pt
    void_p data; //void *

    void_p conf_file; //u_char *
    ngx_uint_t line;
} ngx_path_t;

typedef struct ngx_file_s {
    uint64 fd;
    ngx_str_t name;
    uint64 info[18]; // ngx_file_info_t (aka struct stat)

    off_t offset;
    off_t sys_offset;

    void_p log; //ngx_log_t *

	uint64 flags;
/*
    unsigned valid_info:1;
    unsigned directio:1;
*/
} ngx_file_t;

typedef struct {
    ngx_file_t file;
    off_t offset;
    void_p path; //ngx_path_t *
    void_p pool; //ngx_pool_t *
    void_p warn; //char *

    ngx_uint_t access;

	uint64 flags;
/*
    unsigned log_level:8;
    unsigned persistent:1;
    unsigned clean:1;
    unsigned thread_write:1;
*/
} ngx_temp_file_t;

typedef struct ngx_event_pipe_s {
    void_p upstream; //ngx_connection_t *
    void_p downstream; //ngx_connection_t *

    void_p free_raw_bufs; //ngx_chain_t *
    void_p in; //ngx_chain_t *
    void_p last_in; //ngx_chain_t **
    void_p writing; //ngx_chain_t *
    void_p out; //ngx_chain_t *
    void_p free; //ngx_chain_t *
    void_p busy; //ngx_chain_t *
    void_p input_filter; //ngx_event_pipe_input_filter_pt
    void_p input_ctx; //void *
    void_p output_filter; //ngx_event_pipe_output_filter_pt
    void_p output_ctx; //void *

	uint64 flags;
/*
    unsigned read:1;
    unsigned cacheable:1;
    unsigned single_buf:1;
    unsigned free_bufs:1;
    unsigned upstream_done:1;
    unsigned upstream_error:1;
    unsigned upstream_eof:1;
    unsigned upstream_blocked:1;
    unsigned downstream_done:1;
    unsigned downstream_error:1;
    unsigned cyclic_temp_file:1;
    unsigned aio:1;
*/

    ngx_int_t allocated;
    ngx_bufs_t bufs;
    ngx_buf_tag_t tag;

    ssize_t busy_size;

    off_t read_length;
    off_t length;

    off_t max_temp_file_size;
    ssize_t temp_file_write_size;

    ngx_msec_t read_timeout;
    ngx_msec_t send_timeout;
    ssize_t send_lowat;

    void_p pool; //ngx_pool_t *
    void_p log; //ngx_log_t *

    void_p preread_bufs; //ngx_chain_t *
    size_t preread_size;
    void_p buf_to_file; //ngx_buf_t *

    size_t limit_rate;
    time_t start_sec;

    void_p temp_file; //ngx_temp_file_t *

	int num;
} ngx_event_pipe_t;


typedef struct ngx_http_upstream_rr_peer_s {
    void_p sockaddr; // struct sockaddr*
    uint32                       socklen;
    ngx_str_t                       name;
    ngx_str_t                       server;

    ngx_int_t                       current_weight;
    ngx_int_t                       effective_weight;
    ngx_int_t                       weight;

    ngx_uint_t                      conns;
    ngx_uint_t                      max_conns;

    ngx_uint_t                      fails;
    time_t                          accessed;
    time_t                          checked;

    ngx_uint_t                      max_fails;
    time_t                          fail_timeout;
    ngx_msec_t                      slow_start;
    ngx_msec_t                      start_time;

    ngx_uint_t                      down;

    void_p ssl_session; //void                           *
    int                             ssl_session_len;

    ngx_atomic_t                    lock;

    void_p next; //ngx_http_upstream_rr_peer_t    *
} ngx_http_upstream_rr_peer_t;

typedef struct ngx_http_upstream_rr_peers_s {
    ngx_uint_t                      number;

    void_p shpool; //ngx_slab_pool_t                *
    uint64                    rwlock;
    void_p zone_next; //ngx_http_upstream_rr_peers_t   *
    ngx_uint_t                      total_weight;

    uint64 bitfield;
    /*
    unsigned                        single:1;
    unsigned                        weighted:1;
    */

    void_p name; //ngx_str_t                      *

    void_p next; //ngx_http_upstream_rr_peers_t   *

    void_p peer; //ngx_http_upstream_rr_peer_t    *
} ngx_http_upstream_rr_peers_t;


typedef struct {
    void_p init_upstream; //ngx_http_upstream_init_pt
    void_p init; //ngx_http_upstream_init_peer_pt
    void_p data; //void * (actually ngx_http_upstream_rr_peer_data_t)
} ngx_http_upstream_peer_t;


typedef struct {
    ngx_str_t name;
    void_p addrs; //ngx_addr_t *
    ngx_uint_t naddrs;
    ngx_uint_t weight;
    ngx_uint_t max_conns;
    ngx_uint_t max_fails;
    time_t fail_timeout;
    ngx_msec_t slow_start;
    ngx_uint_t down;

    uint32_t backup;
} ngx_http_upstream_server_t;

typedef struct ngx_http_upstream_srv_conf_s {
    ngx_http_upstream_peer_t peer;
    void_p srv_conf; //void **

    void_p servers; //ngx_array_t *

    ngx_uint_t flags;
    ngx_str_t host;
    void_p file_name; //u_char *
    ngx_uint_t line;
    in_port_t port;
    ngx_uint_t no_port;


    void_p shm_zone; //ngx_shm_zone_t *

} ngx_http_upstream_srv_conf_t;

typedef struct {
    void_p upstream; // ngx_http_upstream_srv_conf_t*

    ngx_msec_t connect_timeout;
    ngx_msec_t send_timeout;
    ngx_msec_t read_timeout;
    ngx_msec_t next_upstream_timeout;

    size_t send_lowat;
    size_t buffer_size;
    size_t limit_rate;

    size_t busy_buffers_size;
    size_t max_temp_file_size;
    size_t temp_file_write_size;

    size_t busy_buffers_size_conf;
    size_t max_temp_file_size_conf;
    size_t temp_file_write_size_conf;

    ngx_bufs_t bufs;

    ngx_uint_t ignore_headers;
    ngx_uint_t next_upstream;
    ngx_uint_t store_access;
    ngx_uint_t next_upstream_tries;
    ngx_flag_t buffering;
    ngx_flag_t request_buffering;
    ngx_flag_t pass_request_headers;
    ngx_flag_t pass_request_body;

    ngx_flag_t ignore_client_abort;
    ngx_flag_t intercept_errors;
    ngx_flag_t cyclic_temp_file;
    ngx_flag_t force_ranges;

    void_p temp_path; //ngx_path_t*

    ngx_hash_t hide_headers_hash;
    void_p hide_headers ; // ngx_array_t *
    void_p pass_headers ; // ngx_array_t *

    void_p local;//ngx_http_upstream_local_t*
    ngx_flag_t socket_keepalive;


    void_p cache_zone;//ngx_shm_zone_t*
    void_p cache_value ; // ngx_http_complex_value_t *

    ngx_uint_t cache_min_uses;
    ngx_uint_t cache_use_stale;
    ngx_uint_t cache_methods;

    off_t cache_max_range_offset;

    ngx_flag_t cache_lock;
    ngx_msec_t cache_lock_timeout;
    ngx_msec_t cache_lock_age;

    ngx_flag_t cache_revalidate;
    ngx_flag_t cache_convert_head;
    ngx_flag_t cache_background_update;

    void_p cache_valid ; // ngx_array_t *
    void_p cache_bypass ; // ngx_array_t *
    void_p cache_purge ; // ngx_array_t *
    void_p no_cache ; // ngx_array_t *


    void_p store_lengths ; // ngx_array_t *
    void_p store_values ; // ngx_array_t *


    /*
    int cache:2;

    int store:2;
    int intercept_404:1;
    int change_buffering:1;
    int pass_trailers:1;
    int preserve_output:1;
    */
    uint64 bitfield;


    void_p ssl; //ngx_ssl_t*
    ngx_flag_t ssl_session_reuse;

    void_p ssl_name; //ngx_http_complex_value_t*
    ngx_flag_t ssl_server_name;
    ngx_flag_t ssl_verify;


    ngx_str_t module;
} ngx_http_upstream_conf_t;

typedef struct {
    void_p flushes ; // ngx_array_t                   *
    void_p lengths ; // ngx_array_t                   *
    void_p values ; // ngx_array_t                   *
    ngx_hash_t                     hash;
} ngx_http_proxy_headers_t;

typedef struct {
    ngx_str_t                      key_start;
    ngx_str_t                      schema;
    ngx_str_t                      host_header;
    ngx_str_t                      port;
    ngx_str_t                      uri;
} ngx_http_proxy_vars_t;

typedef struct {
    ngx_http_upstream_conf_t upstream;

    void_p body_flushes ; // ngx_array_t *
    void_p body_lengths ; // ngx_array_t *
    void_p body_values ; // ngx_array_t *
    ngx_str_t body_source;

    ngx_http_proxy_headers_t headers;

    ngx_http_proxy_headers_t headers_cache;

    void_p headers_source ; // ngx_array_t *

    void_p proxy_lengths ; // ngx_array_t *
    void_p proxy_values ; // ngx_array_t *

    void_p redirects ; // ngx_array_t *
    void_p cookie_domains ; // ngx_array_t *
    void_p cookie_paths ; // ngx_array_t *
    void_p cookie_flags ; // ngx_array_t *

    void_p method ; // ngx_http_complex_value_t *
    ngx_str_t location;
    ngx_str_t url;


    ngx_http_complex_value_t cache_key;


    ngx_http_proxy_vars_t vars;

    ngx_flag_t redirect;

    ngx_uint_t http_version;

    ngx_uint_t headers_hash_max_size;
    ngx_uint_t headers_hash_bucket_size;


    ngx_uint_t ssl;
    ngx_uint_t ssl_protocols;
    ngx_str_t ssl_ciphers;
    ngx_uint_t ssl_verify_depth;
    ngx_str_t ssl_trusted_certificate;
    ngx_str_t ssl_crl;
    ngx_str_t ssl_certificate;
    ngx_str_t ssl_certificate_key;
    void_p ssl_passwords ; // ngx_array_t *
    void_p ssl_conf_commands ; // ngx_array_t *

} ngx_http_proxy_loc_conf_t;


typedef struct ngx_http_location_tree_node_s {
    void_p left; //ngx_http_location_tree_node_t*
    void_p right; //ngx_http_location_tree_node_t*
    void_p tree; //ngx_http_location_tree_node_t*

    void_p exact; //ngx_http_core_loc_conf_t*
    void_p inclusive; //ngx_http_core_loc_conf_t*

    u_char                           auto_redirect;
    u_char                           len;
    u_char                           name[1];
} ngx_http_location_tree_node_t;


typedef struct ngx_http_core_loc_conf_s {
    ngx_str_t name;

    void_p regex; //ngx_http_regex_t*


    /*
    int noname:1;
    int lmt_excpt:1;
    int named:1;

    int exact_match:1;
    int noregex:1;

    int auto_redirect:1;

    int gzip_disable_msie6:2;
    int gzip_disable_degradation:2;
    */
    uint64 bitfields;


    void_p static_locations ; // ngx_http_location_tree_node_t *

    void_p regex_locations; //ngx_http_core_loc_conf_s**



    void_p loc_conf; //void**

    uint64 limit_except;
    void_p limit_except_loc_conf;//void**

    void_p handler; //ngx_http_handler_pt*


    size_t alias;
    ngx_str_t root;
    ngx_str_t post_action;

    void_p root_lengths ; // ngx_array_t *
    void_p root_values ; // ngx_array_t *

    void_p types ; // ngx_array_t *
    ngx_hash_t types_hash;
    ngx_str_t default_type;

    off_t client_max_body_size;
    off_t directio;
    off_t directio_alignment;

    size_t client_body_buffer_size;
    size_t send_lowat;
    size_t postpone_output;
    size_t sendfile_max_chunk;
    size_t read_ahead;
    size_t subrequest_output_buffer_size;


    void_p limit_rate ; // ngx_http_complex_value_t *
    void_p limit_rate_after ; // ngx_http_complex_value_t *

    ngx_msec_t client_body_timeout;
    ngx_msec_t send_timeout;
    ngx_msec_t keepalive_timeout;
    ngx_msec_t lingering_time;
    ngx_msec_t lingering_timeout;
    ngx_msec_t resolver_timeout;
    ngx_msec_t auth_delay;

    void_p resolver;//ngx_resolver_t

    time_t keepalive_header;

    ngx_uint_t keepalive_requests;
    ngx_uint_t keepalive_disable;
    ngx_uint_t satisfy;
    ngx_uint_t lingering_close;
    ngx_uint_t if_modified_since;
    ngx_uint_t max_ranges;
    ngx_uint_t client_body_in_file_only;

    ngx_flag_t client_body_in_single_buffer;

    ngx_flag_t internal;
    ngx_flag_t sendfile;
    ngx_flag_t aio;
    ngx_flag_t aio_write;
    ngx_flag_t tcp_nopush;
    ngx_flag_t tcp_nodelay;
    ngx_flag_t reset_timedout_connection;
    ngx_flag_t absolute_redirect;
    ngx_flag_t server_name_in_redirect;
    ngx_flag_t port_in_redirect;
    ngx_flag_t msie_padding;
    ngx_flag_t msie_refresh;
    ngx_flag_t log_not_found;
    ngx_flag_t log_subrequest;
    ngx_flag_t recursive_error_pages;
    ngx_uint_t server_tokens;
    ngx_flag_t chunked_transfer_encoding;
    ngx_flag_t etag;


    ngx_flag_t gzip_vary;

    ngx_uint_t gzip_http_version;
    ngx_uint_t gzip_proxied;


    void_p gzip_disable ; // ngx_array_t *
    ngx_uint_t disable_symlinks;
    void_p disable_symlinks_from ; // ngx_http_complex_value_t *


    void_p error_pages ; // ngx_array_t *

    void_p client_body_temp_path;//ngx_path_t*

    void_p open_file_cache;//ngx_open_file_cache_t*
    time_t open_file_cache_valid;
    ngx_uint_t open_file_cache_min_uses;
    ngx_flag_t open_file_cache_errors;
    ngx_flag_t open_file_cache_events;

    void_p error_log;//ngx_log_t*

    ngx_uint_t types_hash_max_size;
    ngx_uint_t types_hash_bucket_size;

    void_p locations;//ngx_queue_t*
} ngx_http_core_loc_conf_t;


typedef struct ngx_buf_s {
    void_p pos; //u_char *
    void_p last; //u_char *
    off_t file_pos;
    off_t file_last;

    void_p start; //u_char *
    void_p end; //u_char *
    uint64 tag;
    void_p file; //ngx_file_t *
    void_p shadow; //ngx_buf_t *



	uint32 flags;
/*
    unsigned temporary:1;
    unsigned memory:1;


    unsigned mmap:1;

    unsigned recycled:1;
    unsigned in_file:1;
    unsigned flush:1;
    unsigned sync:1;
    unsigned last_buf:1;
    unsigned last_in_chain:1;

    unsigned last_shadow:1;
    unsigned temp_file:1;
*/

	int num;
} ngx_buf_t;


