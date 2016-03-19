data = open('./Date_test').read()
data = str(0x13f3) + data
open('demo.test', 'w').write(data)
