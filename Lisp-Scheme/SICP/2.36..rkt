#lang racket

(define (accumulate op initial seq)
  (if (null? seq)
      initial
      (op (car seq)
          (accumulate op initial (cdr seq)))))

(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      null
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

 (define s (list (list 1 2 3) (list 4 5 6) (list 7 8 9) (list 10 11 12)))
 
 (define (map proc items)
   (if (null? items)
       null
       (cons (proc (car items))
             (map proc (cdr items)))))