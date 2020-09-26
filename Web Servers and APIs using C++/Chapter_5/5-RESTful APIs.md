### Chapter 5: RESTful APIs

##  Creating an endpoint

- Set up a request tester, such as the Restlet extension for Chrome.
- On Firefox, install the RESTED add-on.
- Update `main.cpp` as shown. There can only be one handler for each route.
- Rebuild the server with:
```
/crow_volume$ docker build --rm --no-cache -t hello_crow:latest .
```
- Re-launch the server (the MongoDB service must be running):
```
/crow_volume$ docker run -p 8081:8081 -e PORT=8081 -e MONGODB_URI="mongodb://[ip address]:[mongodb port]/cpp" hello_crow:latest
```
- In RESTED, Send a POST/GET/PUT request to `http://localhost:8081/rest_test`, the response should be 200, with a "rest_test" message.

## Parsing the path

- Update the contact route handler as shown in `main.cpp`.
- Rebuild and re-launch the server.
- Go to `http://localhost:8081/contacts` in a browser.
- Copy the first and last name for one of the entries, and enter it in the URL: `http://localhost:8081/contact/[firstname]/[lastname]`. The contact info should appear.
- Go to `http://localhost:8081/add/[param-1]/[param-2]` and use integers, doubles, and strings to see the add operation on these different data types.
- The order of the route handlers in the program is important: the server will use the first route handler that matches the data types in the path.
