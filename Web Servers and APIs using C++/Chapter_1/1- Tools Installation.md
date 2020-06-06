### Chapter 1: Tools Installation

We will set up a Docker image responsible for building a web server in C++ and serving it over the local network.

1. Install Docker

- On Linux: follow the instructions on the Docker website to install Docker Engine.
- Follow the post-installation instructions so `sudo` is not required for running `docker`.

2. Set up a Docker image

- See the [`Dockerfile`](./Dockerfile) in this folder.
- Use `gcc` version 10 as the base image.
- Install `cmake`, the required `libboost1.67-dev` libraries, `build-essential`, and `libtcmalloc-minimal4`.
- Create a symbolic link at `/usr/lib/libtcmalloc_minimal.so` to point to `/usr/lib/libtcmalloc_minimal.so.4`.

3. Build the Docker image

- Name it `crowbox` with the `-t` option (for "tag"):

```
[...]Chapter_1$ docker build -t crowbox .
```

- To remove an image, get a list of images with `docker images`, then run `docker rmi [IMAGE ID]` and `docker system prune`.

4. Test the image

- We can make sure the image was created by running `docker images`.
- To run the container:

```
[...]Chapter_1$ docker run --rm -ti crowbox:latest bash
root@042e743c5601:/#
```

- `crowbox:latest` specifies which image and version to run.
- `bash` is the  command we want to run.
- The `-ti` option allows us to enter the container through an interactive terminal.
- The `--rm` option removes the container after exiting.
- Exit the container with `exit`.

5. Run a docker container with a volume

- Create a folder inside the working folder called `crow_volume`.
- Use the following syntax to make a folder in the host system available inside the container:

```
docker run -v <host_path>:<container_path> <image> <command>
```

- The `-v` option creates a volume.


- In our case:

```
[...]Chapter_1$ docker run -v [...]Chapter_1/crow_volume:/usr/src/crow_volume --rm -ti crowbox bash
``` 

- Test the volume works by touching a file inside the container and verifying it shows up in the host system.

6. Build a `crow` app

- See the `main.cpp` and `CMakeLists.txt` files for a sample web server. Add them to the `crow_volume` folder.
- Copy the amalgamated header file (`crow_all.h`) from the [crow GitHub repo](https://github.com/ipkn/crow) to the `crow_volume` folder.
- To build the `hello_crow` executable:

```
(Inside container)
/usr/src/crow_volume$ mkdir build
/usr/src/crow_volume$ cd build
/usr/src/crow_volume/build$ cmake ..
...
/usr/src/crow_volume/build$ make
```

7. Serve "Hello, Crow"

- Run a container with a volume and port forwarding using the following syntax:

```
docker run -v <host_path>:<container_path> -p <host_port>:<container_port> -e <env_var>=<environment_variable_value> --rm <image> <command>
```

- `-p` connects the `host_port` to the `container_port`.
- `-e` creates an environment variable.

- In our case:

```
[...]Chapter_1$ docker run -v [...]Chapter_1/crow_volume:/usr/src/crow_volume -p 8081:8081 -e PORT=8081 --rm crowbox /usr/src/crowbox/build/hello_crow
``` 

8. Change the server to display "Hello, \<your-name>"

- Change the string in the `main.cpp` file.
- Run the `make` command in the `crow_volume/build` folder inside the container. This will compile and link the `hello_crow` executable again.
- Re-start the container that runs the `hello_crow` server. 
