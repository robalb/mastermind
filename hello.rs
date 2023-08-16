use std::arch::asm;

fn main() {
    // Statements here are executed when the compiled binary is called.

    // Print text to the console.
    println!("Hello World!");

    // Multiply x by 6 using shifts and adds
    let mut x: u64 = 4;

    unsafe {
        asm!(
            "mov {tmp}, {x}",
            "shl {tmp}, 1",
            "shl {x}, 2",
            "add {x}, {tmp}",
            x = inout(reg) x,
            tmp = out(reg) _,
            );
    }
    println!("{}", x);
}
