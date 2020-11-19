<!-- file misc/README.md -->

# Miscellania #

This `misc/README.md` contain unimportant things useful to `bismon`


Some files here are:

* `misc/test-several-contributors.sh` to test having (so adding and
  removing) several contributors with their passwords
  
* `misc/Dockerfile` to use Docker for a complete Ubuntu 18.04 environment running bismon. 
    * To build the Docker image `docker build -t bismon:latest .`

    * To run bismon in the Docker container `docker run -it -p 8080:8080 bismon:latest` and then `./bismonion --web-base=0.0.0.0:8080 `.
