docker run --privileged --rm tonistiigi/binfmt --install all

docker-buildx-plugin
docker-ce
docker-ce-cli
docker-compose-plugin

{
  "features": {
    "containerd-snapshotter": true
  }
}
