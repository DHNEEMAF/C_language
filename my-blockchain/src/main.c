#include "../include/my_blockchain.h"

int main()
{
    int file_fd;

    struct blockchain buffer;
    buffer.nodes.size = 0;
    buffer.nodes.values = malloc(sizeof(int) * 10);
    buffer.blocks.size = 0;
    buffer.blocks.list = malloc(sizeof(char*) * 10);
    buffer.node_blocks = malloc(sizeof(struct s_node_blocks) * 10);
    for (int i = 0; i < 10; i++)
    {
        buffer.node_blocks[i].content = malloc(sizeof(char*) * 10);
        buffer.node_blocks[i].content_size = 0;
    }

    if ((file_fd = open("blockchain", O_RDONLY)) > 2)
    {
        readbackup(file_fd, &buffer);
        close(file_fd);
    }

    prompt(&buffer);

    if ((file_fd = open("blockchain", O_CREAT | O_WRONLY | O_TRUNC)) > 2)
    {
        writebackup(file_fd, buffer);
        close(file_fd);
    }

    int troll = buffer.nodes.size + (10 - buffer.nodes.size % 10) * ((buffer.nodes.size % 10 + 9) / 10);
    for (int i = 0; i < troll; i++)
    {
        free(buffer.node_blocks[i].content);
    }
    free(buffer.node_blocks);
    free_arr(buffer.blocks.list, buffer.blocks.size);
    free(buffer.nodes.values);

    return 0;
}
