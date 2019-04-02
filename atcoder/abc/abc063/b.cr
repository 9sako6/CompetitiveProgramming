s=read_line
puts s.size == s.split("").uniq.size ? "yes" : "no"