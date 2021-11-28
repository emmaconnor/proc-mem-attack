from util import read_u32

class NginxModule:
    nginx_base = 0
    
    def __init__(self, offset):
        self.offset = offset
        self._ctx_index = None

    @property
    def ctx_index(self):
        if self._ctx_index is None:
            self._ctx_index = read_u32(self.addr)
        return self._ctx_index

    @property
    def addr(self):
        return self.nginx_base + self.offset
        

ngx_core_module = NginxModule(0xe0ae0)
ngx_errlog_module = NginxModule(0xe10a0)
ngx_conf_module = NginxModule(0xe1a00)
ngx_openssl_module = NginxModule(0xe2460)
ngx_regex_module = NginxModule(0xe25e0)
ngx_events_module = NginxModule(0xe1cc0)
ngx_event_core_module = NginxModule(0xe1b60)
ngx_epoll_module = NginxModule(0xe2240)
ngx_http_module = NginxModule(0xe2780)
ngx_http_core_module = NginxModule(0xe2a60)
ngx_http_log_module = NginxModule(0xe5b80)
ngx_http_upstream_module = NginxModule(0xe72c0)
ngx_http_static_module = NginxModule(0xea060)
ngx_http_autoindex_module = NginxModule(0xea220)
ngx_http_index_module = NginxModule(0xea4e0)
ngx_http_mirror_module = NginxModule(0xea680)
ngx_http_try_files_module = NginxModule(0xea860)
ngx_http_auth_basic_module = NginxModule(0xeaa00)
ngx_http_access_module = NginxModule(0xeabe0)
ngx_http_limit_conn_module = NginxModule(0xeae40)
ngx_http_limit_req_module = NginxModule(0xeb1e0)
ngx_http_geo_module = NginxModule(0xeb500)
ngx_http_map_module = NginxModule(0xeb660)
ngx_http_split_clients_module = NginxModule(0xeb860)
ngx_http_referer_module = NginxModule(0xeb9e0)
ngx_http_rewrite_module = NginxModule(0xebbe0)
ngx_http_ssl_module = NginxModule(0xebee0)
ngx_http_proxy_module = NginxModule(0xed3e0)
ngx_http_fastcgi_module = NginxModule(0xee920)
ngx_http_uwsgi_module = NginxModule(0xef800)
ngx_http_scgi_module = NginxModule(0xf0a20)
ngx_http_memcached_module = NginxModule(0xf1620)
ngx_http_empty_gif_module = NginxModule(0xf1ae0)
ngx_http_browser_module = NginxModule(0xf1e40)
ngx_http_upstream_hash_module = NginxModule(0xf2080)
ngx_http_upstream_ip_hash_module = NginxModule(0xf2220)
ngx_http_upstream_least_conn_module = NginxModule(0xf2380)
ngx_http_upstream_random_module = NginxModule(0xf24e0)
ngx_http_upstream_keepalive_module = NginxModule(0xf2680)
ngx_http_upstream_zone_module = NginxModule(0xf2880)
ngx_http_exploit_module = NginxModule(0xf29e0)
ngx_http_write_filter_module = NginxModule(0xe7b40)
ngx_http_header_filter_module = NginxModule(0xe8140)
ngx_http_chunked_filter_module = NginxModule(0xe8260)
ngx_http_range_header_filter_module = NginxModule(0xe84a0)
ngx_http_gzip_filter_module = NginxModule(0xe85e0)
ngx_http_postpone_filter_module = NginxModule(0xe8980)
ngx_http_ssi_filter_module = NginxModule(0xe8fe0)
ngx_http_charset_filter_module = NginxModule(0xe92c0)
ngx_http_userid_filter_module = NginxModule(0xe9640)
ngx_http_headers_filter_module = NginxModule(0xe9b00)
ngx_http_copy_filter_module = NginxModule(0xe9da0)
ngx_http_range_body_filter_module = NginxModule(0xe8380)
ngx_http_not_modified_filter_module = NginxModule(0xe9f40)
