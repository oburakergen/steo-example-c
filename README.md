# Steo with Block Encryption Chat Project C++


#### Algorithms
Participation in the chat room will be via *key*. This key will be given to the users during the program installation and if it is lost, the login process will not be started.
KEY char will be generated via Generator function
> a || b || c || d || e => charGenerator(1000) string
>Formula key = a^2+b^2+c^2+d^2+e^2  

The messages of the user are encrypted as ascii(char(word)) +100 and collected and sent with the key
## by Burak ERGEN 