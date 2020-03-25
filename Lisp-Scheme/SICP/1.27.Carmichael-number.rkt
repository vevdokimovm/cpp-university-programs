#lang racket
(define (square x) (* x x))

(define (even? n) (= (remainder n 2) 0))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
        (remainder (square (expmod base (/ exp 2) m)) m))
        (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (Carmichael-number? n)
  (check-for-Carmichael  n (- n 1)))

(define (check-for-Carmichael n a)
    (if (= a 0) #t
        (if (= (expmod a n n) a) (check-for-Carmichael n (- a 1)) #f)))

     
   
   