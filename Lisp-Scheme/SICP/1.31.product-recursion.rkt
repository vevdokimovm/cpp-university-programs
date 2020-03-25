#lang racket

(define (inc x)
  (+ x 1))

(define (identity x) x)

(define (square x) (* x x))

(define (product term a next b)
  (if (> a b)
      1
      (* (term a) (product term (next a) next b))))

(define (factorial a)
  (product identity 1 inc a))

(define (pi-sum n)
  (* 4 (John-Wallis-method n)))

(define (John-Wallis-method b)
  (define (pi-term x)
    (/ (* 1.0 (- x 1) (+ x 1)) (square x)))
  (define (pi-next x)
    (+ x 2))
  (product pi-term 3 pi-next b))

(define (e x y) (= x y))