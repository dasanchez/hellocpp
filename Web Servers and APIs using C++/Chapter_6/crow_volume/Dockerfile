from bbox:latest

WORKDIR /usr/src/crow_volume
COPY . .

WORKDIR /usr/src/crow_volume/build
RUN cmake .
RUN make
CMD ["./hello_crow"]
