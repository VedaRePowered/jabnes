#!/usr/bin/lua5.3

-- don't even try do anything with this file, the code is the fastest way I can write the code

function fix_len(num, len)
	local str = tostring(num)
	while string.len(str) < len do
		str = 0 .. str
	end
	return str
end

if arg[1] and arg[2] then
	correct_log = io.open(arg[1], "r")
	check_log = io.open(arg[2], "r")
else
	correct_log = io.open("nintendulator_nestest.log", "r")
        check_log = io.open("jabnes_nestest.log", "r")
end

chars = 73
stack_pos = 71

if arg[3] then
	chars = arg[3]
end

if arg[4] then
	stack_pos = arg[4]
end

lines_by_stack = {}

correct_line = "test"
check_line = "test"
same = true
line_number = 0
current_stack_value = "FF"
while correct_line and check_line and same do
	lines_by_stack[current_stack_value] = "(" .. fix_len(line_number, 5) .. ") " .. check_line
	line_number = line_number + 1
	prev_line = check_line
	correct_line = correct_log:read("*line")
	check_line = check_log:read("*line")
	same = string.sub(correct_line, 1, chars) == string.sub(check_line, 1, chars)
	current_stack_value = string.sub(check_line, stack_pos, stack_pos+2)
end

print("Error At Line " .. line_number .. ":")
if lines_by_stack[current_stack_value] then
	print("      Same Stack Line: " .. lines_by_stack[current_stack_value] .. ",")
end
print("      Previous Line:   (" .. fix_len(line_number - 1, 5) .. ") " .. prev_line .. ",")
print("      Actual Line:     (" .. fix_len(line_number, 5) .. ") " .. check_line .. ",")
print("      Expected Line:   (" .. fix_len(line_number, 5) .. ") " .. correct_line .. ",")
print("      Max Compared:    ( ALL ) " .. string.sub("                                                                                                                                ", 1, chars) .. "^ is not checked.")
