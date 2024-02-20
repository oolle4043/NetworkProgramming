FROM ubuntu:latest
LABEL maintainer="cjj"

WORKDIR /app/client

COPY clnt /app/client

RUN chmod +x /app/client/clnt

EXPOSE 3000

CMD ["./clnt", "172.17.0.1", "3000", "test"]

