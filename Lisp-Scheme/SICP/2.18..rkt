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