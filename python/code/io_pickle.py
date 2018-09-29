
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pickle

shoplistFile = 'shoplist.data'

shoplist = ['apple', 'mango', 'carrot']
file = open(shoplistFile, 'wb')
pickle.dump(shoplist, file)
file.close()

del shoplist

file = open(shoplistFile, 'rb')

storedList = pickle.load(file)
print(storedList)
