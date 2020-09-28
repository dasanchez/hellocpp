### Chapter 6: WebSockets and Crow

##  Reviewing the JavaScript client code

- The `websocket.js` file under `public/scripts/` contains WebSockets-related code.
- The `chat.html` file under  `public/` calls that script.

## Creating the C++ server code.

- Update `main.cpp` as shown.
- Rebuild and relaunch the server.
- Go to `http://localhost:8081/chat` in two separate browser windows to verify the chat server works.

## Running WebSockets in Heroku

- To deploy the WebSockets container in Heroku, comment out all the MongoDB-related code, rebuild the container, and run the following:
```
crow_volume$ heroku login
crow_volume$ heroku container:login
crow_volume$ heroku container:push web -a pure-ravine-56641
crow_volume$ heroku container:release web -a pure-ravine-56641
crow_volume$ heroku open -a pure-ravine-56641
```
- The web page should open in a browser.