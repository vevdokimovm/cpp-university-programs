#lang racket
(define (square x) (* x x))
(define (sum-of-squares x y)
(+ (square x) (square y)))
(define (sum-of-biggest-numbers a b c)
(cond ((and (>= a c) (>= b c)) (+ (square a) (square b)))
      ((and (>= a b) (>= c b)) (+ (square a) (square c)))
      ((and (>= b a) (>= c a)) (+ (square b) (square c)))))

(sum-of-biggest-numbers 5 6 7)