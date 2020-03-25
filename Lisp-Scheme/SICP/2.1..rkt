#lang racket

(define (sign x)
  (cond ((< x 0) -1)
        ((> x 0) 1)
        (else 0)))
      

(define (make-rat x y)
  (let ((g (* (gcd (abs x) (abs y)) (sign y))))
      (cons (/ x g) (/ y g))))
    
  

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define numer car)

(define denom cdr)

(define (mul-rat x y)
   (make-rat (* (numer x) (numer y))
        (* (denom x) (denom y))))
         
(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define (min x) (- x))