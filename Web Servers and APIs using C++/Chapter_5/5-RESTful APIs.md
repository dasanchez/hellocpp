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
