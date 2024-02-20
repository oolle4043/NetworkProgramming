FROM ubuntu:latest
LABEL maintainer="cjj"

WORKDIR /app/server

COPY server /app/server

RUN chmod +x /app/server/server

EXPOSE 3000

CMD ["./server", "3000"]

