#lang racket

(define (list-ref items n)
  (if (= n 0)
      (car items)
      (list-ref (cdr items) (- n 1))))

(define (length items)
  (if (null? items)
      0
      (+ 1 (length (cdr items)))))

(define (reverse items)
  (define (reversing len)
    (if (= len 1)
        (list (car items))
        (cons (list-ref items (- len 1)) (reversing (- len 1)))))
  (reversing (length items)))

(define (same-parity x . items)
  (define (even? x)
    (remainder x 2))
  (define (iter items result)
    (cond ((null? items) (reverse result))
          ((= (even? x) (even? (car items))) (iter (cdr items) (cons (car items) result)))
          (else (iter (cdr items) result))))
  (iter items (list x)))