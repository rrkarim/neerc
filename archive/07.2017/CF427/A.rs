#[macro_export]
macro_rules! scanln {
  ($($var:ident : $ty:path),+) => {
    $(let $var: $ty;)+
    {
      use std::io;
      let mut __buf = String::new();
      io::stdin().read_line(&mut __buf).unwrap();
      let mut eles = __buf.split_whitespace();
      $($var = Scan::scan(&mut eles);)+
    }
  }
}

pub trait Scan {
  fn scan<'a, I>(eles: &mut I) -> Self where I: Iterator<Item=&'a str>;
}

macro_rules! impl_scan_single {
  ($ty:ty) => {
    impl Scan for $ty {
      fn scan<'a, I>(eles: &mut I) -> Self where I: Iterator<Item=&'a str> {
        let next = eles.next().unwrap();
        match next.parse() {
          Ok(res) => res,
          Err(_) => panic!()
        }
      }
    }
  }
}

impl_scan_single!(u8);
impl_scan_single!(u16);
impl_scan_single!(u32);
impl_scan_single!(u64);
impl_scan_single!(usize);
impl_scan_single!(i8);
impl_scan_single!(i16);
impl_scan_single!(i32);
impl_scan_single!(i64);
impl_scan_single!(isize);
impl_scan_single!(f32);
impl_scan_single!(f64);
impl_scan_single!(String);

const __IMPL_SCAN_FOR_VEC: () = {
  use std::str::FromStr;
  impl<T> Scan for Vec<T> where T: FromStr {
    fn scan<'a, I>(eles: &mut I) -> Self where I: Iterator<Item=&'a str> {
      eles.map(|str| match str.parse() {
        Ok(res) => res,
        Err(_) => panic!()
      }).collect()
    }
  }
};


fn main() {
  use std::cmp::Ordering;
  scanln!(s: u64, v1: u64, v2: u64, t1: u64, t2: u64);
  let e1 = (s * v1) + (2 * t1);
  let e2 = (s * v2) + (2 * t2);
  println!("{}",
    match e1.cmp(&e2) {
      Ordering::Less => "First",
      Ordering::Greater => "Second",
      Ordering::Equal => "Friendship"
    }
  );
}