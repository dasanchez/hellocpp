### Chapter 3: Building Websites

## Creating HTML Pages

There are a couple wways we can create HTML pages in Crow:

- Pure HTML
- Mixed HTML and Mustache templates

Mustache is a prominent web template system.

Each webpage in crow needs:

- An HTML file in the public directory
- A route handler

### Create a new webpage

- In the `crow_volume` folder, create a new folder called `public`.
- Create an `index.html` file in the `public` folder.

## Serving HTML Pages

- Route handlers look at the path passed to the website and decide which code should handle it.
- Update the `main.cpp` to serve the html file instead of returning a string.
- Go back to the terminal, make in the `build` folder:
```
[...]Chapter_3$ docker run -v [crow_volume path]:/usr/src/crow_volume --rm -ti hello_crow bash
root@4bf6a269fa0d:/usr/src/crow_volume/build# make
```
- Exit the container and relaunch the server
```
[...]Chapter_3/crow_volume$ docker run -v /home/dante/projects/hellocpp/Web\ Servers\ and\ APIs\ using\ C++/Chapter_3/crow_volume:/usr/src/crow_volume -p 8081:8081 -e PORT=8081 --rm hello_crow:latest /usr/src/crow_volume/build/hello_crow
```

## Serving Static Content

- Add three folders to add structure to the public folder: images, scripts, and styles.
