#lang racket

(define (square x) (* x x))

(define (cube x) (* x x x))

(define (identity x) x)

(define (inc x) (+ x 1))

(define (mutually-simple? a b)
  (= (gcd a b) 1))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (filtered-accumulate combiner null-value filter term a next b)
  (define (iter a accumulator)
    (if (> a b)
        accumulator
        (if (filter a)
            (iter (next a) (combiner accumulator (term a)))
            (iter (next a) accumulator))))
  (iter a null-value))

(define (smallest-divisior n test-divisior)
  (define (next h)
    (if (= h 2)
        3
        (+ h 2)))
  (cond ((> (square test-divisior) n) n)
        ((= (remainder n test-divisior) 0) test-divisior)
        (else (smallest-divisior n (next test-divisior)))))

(define (prime? n)
  (if (= n 1)
      #f
      (= (smallest-divisior n 2) n)))

(define (sum filter term a next b)
  (filtered-accumulate + 0 filter term a next b))

(define (sum-prime-cubes a b)
  (sum prime? cube a inc b))

(define (product filter term a next b)
  (filtered-accumulate * 1 filter term a next b))

(define (pro-simples n)
  (define (mutually-simple? k)
  (= (gcd n k) 1))
  (product mutually-simple? identity 1 inc n))