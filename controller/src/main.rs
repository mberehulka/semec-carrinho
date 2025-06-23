use dioxus::prelude::*;
use dioxus::logger::tracing::*;

fn main() {
    dioxus::logger::init(Level::DEBUG).unwrap();
    dioxus::mobile::launch(|| rsx! { "Hello World !" });
}