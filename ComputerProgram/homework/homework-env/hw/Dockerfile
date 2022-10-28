FROM alpine:latest

RUN apk update
RUN apk add gcc make libc-dev valgrind

# Setup Launcher
ADD ./inject.c /
RUN gcc -o /lib/libinject.so -shared -fPIC -O3 /inject.c

RUN addgroup -S runner && adduser -S runner -G runner

USER runner

CMD [ "/bin/sh", "-c", "while true; do sleep 10000; done" ]