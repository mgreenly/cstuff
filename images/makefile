ALPINE_VERSION=latest #3.21.3
BOOKWORM_VERSION=12.9
ARCH=aarch64
OS=Linux

default: bookworm alpine

bookworm:
	docker buildx build --platform linux/amd64 -t bookworm-dev:${BOOKWORM_VERSION} --build-arg BOOKWORM_VERSION=${BOOKWORM_VERSION} -f Dockerfile.bookworm .
	docker tag bookworm-dev:${BOOKWORM_VERSION} bookworm-dev:latest


# alpine:
# 	docker buildx build --platform linux/amd64 -t alpine-dev:${ALPINE_VERSION} --build-arg ALPINE_VERSION=${ALPINE_VERSION} -f Dockerfile.alpine .
# 	docker tag alpine-dev:${ALPINE_VERSION} alpine-dev:latest


alpine:
	docker buildx build \
		--platform linux/arm64/v8 \
		--build-arg ALPINE_VERSION=${ALPINE_VERSION} \
		-t localhost:5000/alpine-dev:${ALPINE_VERSION} \
		-f Dockerfile.alpine .



# apt-get install qemu binfmt-support qemu-user-static
# docker buildx use $(docker buildx create --name foo --platform linux/amd64,linux/arm64/v8)
