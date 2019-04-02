import std.stdio, std.string, std.range;

void main(){
    string s = readln.chomp;
    foreach(i; 0..3){
        if(s[i] == s[i+1]){
            writeln("Bad");
            return;
        }
    }
    writeln("Good");
}