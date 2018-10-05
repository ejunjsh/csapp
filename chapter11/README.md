# chapter11

## precondition
````shell
mkdir cgi-bin
````

## tiny web server

    gcc -o tiny src/tiny.c src/csapp.c
    gcc -o cgi-bin/form-adder src/cgi-bin/form-adder.c

    ./tiny 9090

## 11.6

### build and run

    gcc -o tiny.6 src/tiny.6.c src/csapp.c

    ./tiny.6 9090

### result

In my safari,it use `http/1.1`,below is the output

    GET / HTTP/1.1
    Host: localhost:9090
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
    Upgrade-Insecure-Requests: 1
    Cookie: Hm_lvt_c2da852ee703ae71196b173fd6edef51=1532438293,1534252516
    User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/12.0 Safari/605.1.15
    Accept-Language: en-us
    Accept-Encoding: gzip, deflate
    Connection: keep-alive