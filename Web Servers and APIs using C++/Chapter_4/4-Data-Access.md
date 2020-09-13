### Chapter 4: Data Access

## Create an mLab account

**It looks like mLab is no longer offered as of September 2020. I will keep working on a local MongoDB database.**

## Install Mongo locally

- Install `mongodb` and `mongo-tools` via `apt`.
- Download Robo 3T.
- Set up a database called "cpp" with a "contacts" collection (see the json file):
    - firstName
    - lastName
    - email
    - phone
    - photo: URI to the contact's photo
- In Robo 3T, create a database called cpp, then run the following command:

```
$ mongoimport -h localhost:[port] -d cpp -c contacts --file contacts.json --jsonArray
```
The "d" is for database, and the "c" is for collection. If the collection didn't exist before, it will get created at this point.
- Verify the collection was created in Robo3T.

## Add the MongoDB C++ drivers

- Create a new folder called `bbox` for a Docker container responsible for building the C++ libraries.
- Make a new Docker as shown in the Dockerfile:
```
$ docker build --rm --squash --no-cache -t bbox:latest .
```

## Query MongoDB data

- Update the `CMakeLists.txt` file as shown.
- Update the `crow_volume/Dockerfile` file as shown.
- Update the  `main.cpp` file as shown.
- Modify the local MongoDB configuration so the server accepts requests from the crow container:
    - Open the `/etc/mongodb.conf` file (using `sudo`).
    - Change the  `bind_ip` value to `0.0.0.0`.
    - Restart the MongoDB server  with `sudo service mongodb restart`
- Build a new `hello_crow` image:
    - Go to the `crow_volume` folder and run
```
docker build --rm --no-cache -t hello_crow:latest .
```
- Run the new image:
```
docker run -p 8081:8081 -e PORT=8081 -e MONGODB_URI="mongodb://[host-ip-address]:[host-port]/cpp" hello_crow:latest
```
- Go to `localhost:8081/contacts` in a browser and you will see a list of the first 10 collection records.


## Add dynamic data to a page

- Crow supports a logic list template system called Mustache.
- Update `main.cpp` as shown.
- Create `contacts.html` as shown.
- Rebuild the image:
```
[...]/crow_volume$ docker build --rm --no-cache -t hello_crow:latest .
```
- Run the server image again:
```
docker run -p 8081:8081 -e PORT=8081 -e MONGODB_URI="mongodb://[host-ip-address]:[host-port]/cpp" hello_crow:latest
```
- Go to `localhost:8081/contacts` in a browser, the contacts table will be displayed using the bulma style.
- Go to `localhost:8081/contacts/[email from contact list]`, the contact info will be displayed in raw text form.