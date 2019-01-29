#!/usr/bin/lua5.3

-- generate testing pallet file
local fname = "generated.pal"
if arg[1] then
	fname = arg[1]
end
local pattern = "4-bits"
if arg[2] then
	pattern = arg[2]
end

local f = io.open(fname, "wb")

for i = 0, 63 do
	if pattern == "4-bits" then
		f:write(string.char(math.floor((i&03)/3  * 255)))
		f:write(string.char(math.floor((i&12)/12 * 255)))
		f:write(string.char(math.floor((i&48)/48 * 255)))
	end
end
