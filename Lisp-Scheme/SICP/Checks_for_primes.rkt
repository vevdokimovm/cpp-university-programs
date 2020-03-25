#lang racket
(define (square x) (* x x))

(define (smallest-divisior n)
  (find-divisior n 2))
  
(define (find-divisior n test-divisior)
  (cond ((> (square test-divisior) n) n)
       ((= (remainder n test-divisior) 0) test-divisior)
       (else (find-divisior n (+ test-divisior 1)))))

(define (prime? n)
  (= (smallest-divisior n) n))

(define (timed-prime-test n)
  (start-prime-test n (current-milliseconds)))

(define (start-prime-test n start-time)
  (when (prime? n)
      (report-prime n (- (current-milliseconds) start-time))))

(define (report-prime n elapsed-time)
  (newline)
  (display n)
  (display " *** ")
  (display elapsed-time))

(define (even? n) (= (remainder n 2) 0))

(define (search-for-primes start last)
   (define (prime-iter cur last)
     (when (<= cur last) (timed-prime-test cur))
     (when (<= cur last) (prime-iter (+ cur 2) last)))
   (prime-iter (if (even? start) (+ start 1) start) last)) 
     
   
   