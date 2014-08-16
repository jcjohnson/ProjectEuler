gets.strip.split(",").map{|s| s.chars.map{|c| c == "\"" ? "" : c}.join}.each{|s| puts s}
