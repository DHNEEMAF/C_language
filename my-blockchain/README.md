![linkedin_banner_image_1](https://user-images.githubusercontent.com/67286684/124254379-dd475800-dadd-11eb-9853-15a76669c27e.png)

# My_blockchain in C programming language

This is a simple and custom blockchain implementation in C programming language.

Blockchain is a command that allows for the creation and management of a blockchain. When the program starts (it loads a backup if there is one) then a prompt appears. This prompt allows to execute commands. When the commands are not successful they display "nok: info" or info is an error message - see below:
- add node nid add a nid identifier to the blockchain node.
- rm node nid... remove nodes from the blockchain with a nid identifier. If nid is '*', then all nodes are impacted.
- add block bid nid... add a bid identifier block to nodes identified by nid. If nid is '*', then all nodes are impacted.
- rm block bid... remove the bid identified blocks from all nodes where these blocks are present.
- ls list all nodes by their identifiers. The option -l attaches the blocks bid's associated with each node.
- sync synchronize all of the nodes with each other. Upon issuing this command, all of the nodes are composed of the same blocks.
- quit save and leave the blockchain.

The blockchain prompt displays:

- a [ character
- a first letter that indicates the state of synchronization of the chain:
- "s" if the blockchain is synchronized
- "-" if the blockchain is not synchronized.
- n number of nodes in the chain.
- the "]> " string (with a space)

# Error messages:

- nok: no more resources available on the computer
- nok: this node already exists
- nok: this block already exists
- nok: node doesn't exist
- nok: block doesn't exist
- nok: command not found
- nok: incorrect number arguments
- nok: no nodes in the blockchain

# Authorized function(s)

- malloc(3)
- free(3)
- printf(3)
- write(2)
- open(2)
- read(2)
- close(2)

# **** Instruction on how to compile and use my_blockchain ****
1. Go to ex00 directory
2. Because I created a makefile for this program, you can compile the files by typing "make"
3. It will give you the output "my_blockchain"
4. Type ./my_blockchain and run the program
5. Use the commands listed above
6. To clean/remove the .o files, type "make clean" in your terminal

# Conclusion

As a result of this project, we learned a lot about blockchain and how to implement it, which we have never tried before.
This project taught us how to design a relatively large project, dividing it into partitions and connect them with each other, and also how to create custom complex data structures and manipulate them. Moreover, the program has no memory leaks and we spent quite a lot of time learning how to ensure that.
