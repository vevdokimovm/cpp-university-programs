#lang racket

(define (enumerate-interval low high)
  (if (> low high)
      null
      (cons low (enumerate-interval (+ low 1) high))))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (unique-pairs n)
  (accumulate append
              null
              (map (lambda (i) (map (lambda (j) (list i j))
                                    (enumerate-interval 1 n)))
                   (enumerate-interval 1 n))))

(define (unique-triplets n)
  (accumulate append
              null
              (map (lambda (pair) (map (lambda (k) (append pair (list k)))
                                       (enumerate-interval 1 n)))
                   (unique-pairs n))))

(define (filter predicate? seq)
  (cond ((null? seq) null)
        ((predicate? (car seq))
         (cons (car seq)
               (filter predicate? (cdr seq))))
        (else (filter predicate? (cdr seq)))))

(define (proc n s)
  (define (sum-equal-to-number triple)
    (= (+ (car triple) (cadr triple) (caddr triple)) s))
  (filter sum-equal-to-number (unique-triplets n)))
  