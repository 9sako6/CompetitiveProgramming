fn main() {
    solve_a();
}

fn solve_a() {
    proconio::input! {s: String};
    if s.contains('7') {
        println!("Yes");
    } else {
        println!("No");
    }
}
