### Chapter 2: Deploying to Heroku

## Create a Heroku account

##  Install Heroku-CLI Install in Linux Mint

Use the following command:

```
curl https://cli-assets.heroku.com/install-ubuntu.sh | sh
```

## Deploying our Container to Heroku

### 1. Containerize our app

Put the working version of our docker container in an image.

- Run the latest version of our image:
```
[...]Chapter_2$ docker run --rm -ti crowbox:latest bash
```

- Leave that container running (call it window 1) and open another window.

- In window 2, get a list of the running containers:
```
[...]Chapter_2/crow_volume$ docker ps
```

- Copy the container ID and run the following command:
```
[...]Chapter_2/crow_volume$ docker cp . [CONTAINER ID]:/usr/src/crow_volume
```

- Commit the changes back to an image:
```
[...]Chapter_2/crow_volume$ docker commit [CONTAINER ID] hello_crow:latest
```

- Create Dockerfile as shown in this folder


### 2. Heroku login

- Go to crow_volume and login to heroku:
```
[...]Chapter_2/crow_volume$ heroku login
```

- Log into the container service of Heroku:
```
[...]Chapter_2/crow_volume$ heroku container:login
```

### 3. Create a Heroku app

- Create a Heroku app
```
[...]/Chapter_2/crow_volume$ heroku create
Creating app... done, ⬢ pure-ravine-56641
https://pure-ravine-56641.herokuapp.com/ | https://git.heroku.com/pure-ravine-56641.git
```

- Build the app:
```
[...]/Chapter_2/crow_volume$ docker build -t hello_crow .
```

### 4. Push the container to Heroku and release it
- Push the container to Heroku
```
[...]/Chapter_2/crow_volume$ heroku container:push web -a [app name]
```
"web" is for "web app. In our case:
```
[...]/Chapter_2/crow_volume$ heroku container:push web -a pure-ravine-56641
```
This will take a while.

- Release the app in Heroku:
```
[...]/Chapter_2/crow_volume$ heroku container:release web -a [app name]
```
In our case:
```
[...]/Chapter_2/crow_volume$ heroku container:release web -a pure-ravine-56641
```

### 5. Test in the browser
- Open the app with Heroku:
```
[...]/Chapter_2/crow_volume$ heroku open -a [app name]
```
In our case:
```
[...]/Chapter_2/crow_volume$ heroku open -a pure-ravine-56641
```

## Optional: Push the image to Docker Hub