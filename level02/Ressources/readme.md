# Rainfall03

b *0x08048500
set $eax = 0xb0000000
//Allows us to get to the printf part

python -c 'print((75 * "\x41") )' > /tmp/payload

Gives stable results
We gotta overflow again