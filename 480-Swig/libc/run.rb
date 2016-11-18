#!/usr/bin/ruby

random_data = ""
1000.times {  random_data << rand(255) }
open('source.txt', 'w') { |f| f << random_data }

require 'libc'

f1 = Libc.fopen('source.txt', 'r')
f2 = Libc.fopen('dest.txt', 'w+')

buffer = Libc.malloc(1024)

nread = Libc.fread(buffer, 1, 1024, f1)

while nread > 0
  Libc.fwrite(buffer, 1, nread, f2)
  nread = Libc.fread(buffer, 1, 1024, f1)
end
Libc.fclose(f1)
Libc.fclose(f2)

# teraz plik dest.txt zawiera to samo co plik source.txt

puts random_data == open('dest.txt', 'r') { |f| f.read }
