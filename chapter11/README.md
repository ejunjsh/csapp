# chapter11

## precondition
````shell
mkdir cgi-bin
````

## build original tiny web server

    gcc -o tiny src/tiny.c src/csapp.c

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

## 11.7

### build and run

    gcc -o tiny.7 src/tiny.7.c src/csapp.c

    ./tiny.7 9090

### test

navigate to [http://localhost:9090/example.mpeg](http://localhost:9090/example.mpeg)

## 11.8

### build and run

    gcc -o tiny.8 src/tiny.8.c src/csapp.c

    ./tiny.8 9090

## 11.9

### build and run

    gcc -o tiny.9 src/tiny.9.c src/csapp.c

    ./tiny.9 9090

## 11.10

### build cgi

    gcc -o cgi-bin/form-adder src/cgi-bin/form-adder.c

### use original tiny to run

    ./tiny 9090

### see result in browser

[http://localhost:9090](http://localhost:9090)

## 11.11

### build cgi

    gcc -o cgi-bin/head-adder src/cgi-bin/head-adder.c

### build and run

    gcc -o tiny.11 src/tiny.11.c src/csapp.c

    ./tiny.11 9090

### telent test

    ➜ telnet localhost 9090
    Trying ::1...
    Connected to localhost.
    Escape character is '^]'.
    HEAD /

    HTTP/1.0 200 OK
    Server: Tiny Web Server
    Connection: close
    Content-length: 325
    Content-type: text/html

    Connection closed by foreign host.

you will see the `HEAD /` only get the header , there are not body.This is `HEAD` method that don't return body.