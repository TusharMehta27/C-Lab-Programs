#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  char buf[1024];
  int n;

  /* Create a raw socket */
  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  /* Bind the socket to all interfaces */
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(0);
  if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  /* Set the socket to promiscuous mode */
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_ promisc, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  /* Receive packets */
  while (1) {
    clilen = sizeof(cliaddr);
    n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &cliaddr, &clilen);
    if (n < 0) {
      perror("recvfrom");
      exit(1);
    }

    /* Print the packet */
    printf("Packet from %s:\n", inet_ntoa(cliaddr.sin_addr));
    printf("%s\n", buf);
  }

  close(sockfd);
  return 0;
}