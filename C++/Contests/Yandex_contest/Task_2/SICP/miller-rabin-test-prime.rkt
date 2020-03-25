#lang racket

(define (square x) (* x x))

(define (check-for-trivial num m remainder)
  (if (and (not (= num 1)) (not (= num (- m 1))) (= remainder 1))
      0
      remainder))
  
(define (trivial-square? num m)
  (check-for-trivial num m (remainder (square num) m)))
  
(define (modified-expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
        (trivial-square? (modified-expmod base (/ exp 2) m) m))
        (else (remainder (* base (modified-expmod base (- exp 1) m)) m))))
  
(define (Miller-Rabin-test n) 
  (define (Miller-Rabin-iteration a counter n) 
    (define (try-it a) 
      (= (modified-expmod a (- n 1) n) 1)) 
    (if (= a n) 
        (> counter (/ n 2)) 
        (if (try-it a) 
            (Miller-Rabin-iteration (+ a 1) (+ counter 1) n) 
            (Miller-Rabin-iteration (+ a 1) counter n)))) 
  (Miller-Rabin-iteration 1 0 n))

(define (prime? n)
  (if (or (even? n) (= n 2))
      (if (= n 2) 
          #t
          #f)
      (Miller-Rabin-test n)))
          